include $(TOPDIR)/rules.mk

PKG_NAME:=megacmd
PKG_VERSION:=2.4.0
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://github.com/meganz/MEGAcmd.git
PKG_SOURCE_VERSION:=2.4.0_Linux
PKG_MIRROR_HASH:=skip

PKG_INSTALL:=1
PKG_BUILD_PARALLEL:=1

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
	MAINTAINER:=Your Name
endef

define Package/megacmd/description
	MEGAcmd provides non UI access to MEGA services.
	This package builds version 2.x using CMake without vcpkg.
endef

# Disable vcpkg and provide cryptopp paths
CMAKE_OPTIONS += \
	-DUSE_VCPKG=OFF \
	-DENABLE_VCPKG=OFF \
	-DCMAKE_DISABLE_FIND_PACKAGE_Vcpkg=ON \
	-DFULL_REQS=OFF \
	-DUSE_PDFIUM=OFF \
	-DUSE_FREEIMAGE=OFF \
	-DUSE_FFMPEG=ON \
	-DFUSE_INCLUDE_DIR=$(STAGING_DIR)/opt/include/fuse \
	-DFUSE_LIBRARY=$(STAGING_DIR)/opt/lib/libfuse.so \
	-DCRYPTOPP_INCLUDE_DIR=$(STAGING_DIR)/opt/include \
	-DCRYPTOPP_LIBRARY=$(STAGING_DIR)/opt/lib/libcryptopp.so \
	-DCMAKE_INSTALL_PREFIX=/opt \
	-DCMAKE_INSTALL_BINDIR=bin \
	-DCMAKE_INSTALL_LIBDIR=lib \
	-DBUILD_SHARED_LIBS=ON

define Package/megacmd/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/mega-* $(1)/opt/bin/
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libmega.so* $(1)/opt/lib/
	$(INSTALL_DIR) $(1)/opt/etc/bash_completion.d
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/opt/etc/bash_completion.d/megacmd_completion.sh $(1)/opt/etc/bash_completion.d/
	$(INSTALL_DIR) $(1)/opt/etc/sysctl.d
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/opt/etc/sysctl.d/99-megacmd-inotify-limit.conf $(1)/opt/etc/sysctl.d/
endef

$(eval $(call BuildPackage,megacmd))
