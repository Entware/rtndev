include $(TOPDIR)/rules.mk

PKG_NAME:=megacmd
PKG_VERSION:=2.4.0
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://github.com/meganz/MEGAcmd.git
PKG_SOURCE_VERSION:=2.4.0_Linux
PKG_MIRROR_HASH:=skip

PKG_LICENSE:=BSD-2-Clause GPL-3.0-or-later
PKG_LICENSE_FILES:=LICENSE
PKG_MAINTAINER:=Your Name <your.email@example.com>

PKG_INSTALL:=1
PKG_BUILD_PARALLEL:=1
PKG_FIXUP:=libtool

CMAKE_BINARY_SUBDIR:=.build

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/megacmd
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=File Transfer
	DEPENDS:=+icu +libcares +libcryptopp +libcurl +libmediainfo \
		+libpcrecpp +libreadline +libsodium +libsqlite3 +libuv \
		+libopenssl +libffmpeg-full +libfuse +zlib
	TITLE:=Command Line Interactive and Scriptable Application
	URL:=https://github.com/meganz/megacmd
endef

define Package/megacmd/description
	MEGAcmd provides non-UI access to MEGA services. It features a
	server-client architecture where the server handles all cloud
	operations and multiple clients can send commands to it.

	This package includes command-line tools for file transfer,
	synchronization, and cloud storage management.

	License: BSD-2-Clause AND GPL-3.0-or-later
	See /opt/share/doc/megacmd/LICENSE for full license text.
endef

# Check if tests are enabled via environment variable
# Usage: make package/feeds/rtndev/megacmd/compile MEGACMD_ENABLE_TESTS=1
ifeq ($(MEGACMD_ENABLE_TESTS),1)
CMAKE_OPTIONS += \
	-DENABLE_MEGACMD_TESTS=ON \
	-DFETCHCONTENT_FULLY_DISCONNECTED=OFF \
	-DFETCHCONTENT_QUIET=OFF
else
# Default: disable tests for production builds
CMAKE_OPTIONS += \
	-DENABLE_MEGACMD_TESTS=OFF
endif

# Disable vcpkg and external package managers
CMAKE_OPTIONS += \
	-DUSE_VCPKG=OFF \
	-DENABLE_VCPKG=OFF \
	-DCMAKE_DISABLE_FIND_PACKAGE_Vcpkg=ON \
	-DFULL_REQS=OFF

# Feature selection
CMAKE_OPTIONS += \
	-DUSE_PDFIUM=OFF \
	-DUSE_FREEIMAGE=OFF \
	-DUSE_FFMPEG=ON \
	-DUSE_PCRE=ON \
	-DENABLE_MEDIA_FILE_METADATA=ON \
	-DUSE_READLINE=ON \
	-DUSE_LIBUV=ON \
	-DUSE_OPENSSL=ON

# Library paths for Entware staging
CMAKE_OPTIONS += \
	-DFUSE_INCLUDE_DIR=$(STAGING_DIR)/opt/include/fuse \
	-DFUSE_LIBRARY=$(STAGING_DIR)/opt/lib/libfuse.so \
	-DCRYPTOPP_INCLUDE_DIR=$(STAGING_DIR)/opt/include \
	-DCRYPTOPP_LIBRARY=$(STAGING_DIR)/opt/lib/libcryptopp.so

# Installation configuration
CMAKE_OPTIONS += \
	-DCMAKE_INSTALL_PREFIX=/opt \
	-DCMAKE_INSTALL_BINDIR=bin \
	-DCMAKE_INSTALL_LIBDIR=lib \
	-DBUILD_SHARED_LIBS=ON

define Package/megacmd/conffiles
/opt/etc/sysctl.d/99-megacmd-inotify-limit.conf
endef

# Custom test hook - runs after Build/Compile if tests are enabled
define Build/RunTests
	echo ""; \
	echo "========================================"; \
	echo "Running MEGAcmd Tests"; \
	echo "========================================"; \
	echo ""; \
	echo "Note: Tests require Google Test which will be downloaded during build"; \
	echo ""; \
	cd $(PKG_BUILD_DIR)/$(CMAKE_BINARY_SUBDIR) && \
	export MEGACMD_TEST_USER=$(MEGACMD_TEST_USER) MEGACMD_TEST_PASS=$(MEGACMD_TEST_PASS) && export LD_LIBRARY_PATH=$(PKG_BUILD_DIR)/$(CMAKE_BINARY_SUBDIR)/sdk:$(PKG_BUILD_DIR)/$(CMAKE_BINARY_SUBDIR)/lib:$(STAGING_DIR)/opt/lib:$(TOOLCHAIN_DIR)/lib:$$$$$$$$LD_LIBRARY_PATH && \
	if [ -f mega-cmd-tests-unit ]; then \
		echo "Running unit tests..."; \
		if [ -x "$(TOOLCHAIN_DIR)/lib/ld-linux-x86-64.so.2" ]; then \
			$(TOOLCHAIN_DIR)/lib/ld-linux-x86-64.so.2 ./mega-cmd-tests-unit --gtest_brief=1 || { echo "Unit tests failed!"; exit 1; }; \
		else \
			./mega-cmd-tests-unit --gtest_brief=1 || { echo "Unit tests failed!"; exit 1; }; \
		fi; \
		echo ""; \
	else \
		echo "Warning: Unit test binary not found"; \
	fi; \
	if [ -f mega-cmd-tests-integration ]; then \
		echo "Running integration tests..."; \
		echo "Note: Integration tests may require network access and MEGA credentials"; \
		if [ -x "$(TOOLCHAIN_DIR)/lib/ld-linux-x86-64.so.2" ]; then \
			$(TOOLCHAIN_DIR)/lib/ld-linux-x86-64.so.2 ./mega-cmd-tests-integration --gtest_brief=1 || { echo "Integration tests failed (may be expected without credentials)"; }; \
		else \
			./mega-cmd-tests-integration --gtest_brief=1 || { echo "Integration tests failed (may be expected without credentials)"; }; \
		fi; \
		echo ""; \
	else \
		echo "Warning: Integration test binary not found"; \
	fi; \
	echo "========================================"; \
	echo "Test execution completed"; \
	echo "========================================"; \
	echo "";
endef

# Hook the test execution after compilation
ifeq ($(MEGACMD_ENABLE_TESTS),1)
  Hooks/Compile/Post += Build/RunTests
endif

define Package/megacmd/install
	# Install binaries
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/mega-* $(1)/opt/bin/
	rm -f $(1)/opt/bin/mega-cmd-tests-*

	# Install shared library
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libmega.so* $(1)/opt/lib/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libg{test,mock}*.so* $(1)/opt/lib/

	# Install bash completion
	$(INSTALL_DIR) $(1)/opt/etc/bash_completion.d
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/opt/etc/bash_completion.d/megacmd_completion.sh \
		$(1)/opt/etc/bash_completion.d/

	# Install sysctl configuration for inotify limits
	$(INSTALL_DIR) $(1)/opt/etc/sysctl.d
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/opt/etc/sysctl.d/99-megacmd-inotify-limit.conf \
		$(1)/opt/etc/sysctl.d/

	# Install license documentation (BSD-2-Clause compliance)
	$(INSTALL_DIR) $(1)/opt/share/doc/megacmd
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/LICENSE $(1)/opt/share/doc/megacmd/

	# Install README if present
	[ ! -f $(PKG_BUILD_DIR)/README.md ] || \
		$(INSTALL_DATA) $(PKG_BUILD_DIR)/README.md $(1)/opt/share/doc/megacmd/
endef

define Package/megacmd/postinst
#!/bin/sh
# Apply sysctl settings if system supports it
if [ -f /opt/etc/sysctl.d/99-megacmd-inotify-limit.conf ] && [ -x /opt/sbin/sysctl ]; then
	/opt/sbin/sysctl -p /opt/etc/sysctl.d/99-megacmd-inotify-limit.conf 2>/dev/null || true
fi

echo ""
echo "MEGAcmd installed successfully."
echo "Run 'mega-help' to get started or 'mega-cmd-server' to start the server."
echo ""
echo "License: BSD-2-Clause AND GPL-3.0-or-later"
echo "See /opt/share/doc/megacmd/LICENSE for full license text."
echo ""
exit 0
endef

define Package/megacmd/prerm
#!/bin/sh
# Kill running mega-cmd-server instances
killall mega-cmd-server 2>/dev/null || true
exit 0
endef

$(eval $(call BuildPackage,megacmd))
