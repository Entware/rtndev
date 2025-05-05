#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=duperemove
PKG_VERSION:=0.15.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/markfasheh/duperemove/tar.gz/v$(PKG_VERSION)?
PKG_HASH:=68cc28f5aa43fa2034e512f7b22cf5282ce2b0319b4e1061f7cdf55cc134273b

PKG_MAINTAINER:=Keith Garner <kgarner@kgarner.com>
PKG_LICENSE:=GPL-2.0
PKG_LICENSE_FILES:=LICENSE

# Set variables used in the source's Makefile
export VERSION="$(PKG_VERSION)"
export IS_RELEASE=1

include $(INCLUDE_DIR)/package.mk

define Package/duperemove
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Filesystem
	TITLE:=Duplicate file removal tool
	URL:=https://github.com/markfasheh/duperemove
	# This "pkg-config" is reportedly needed by duperemove but it seems to compile fine without it.
	DEPENDS:= \
		+libsqlite3 \
		+glib2 \
		+libxxhash \
		+libuuid \
		+libmount \
		+libblkid \
		+libbsd \
		+libatomic
endef

define Package/duperemove/description
 Duperemove is a simple tool for finding duplicated extents and submitting
 them for deduplication. When given a list of files it will hash their
 contents on an extent by extent basis and compare those hashes to each
 other, finding and categorizing extents that match each other. Optionally,
 a per-block hash can be applied for further duplication lookup. When given
 the -d option, duperemove will submit those extents for deduplication using
 the Linux kernel FIDEDUPRANGE ioctl.
endef

define Package/duperemove/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/duperemove $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/hashstats $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/btrfs-extent-same $(1)/usr/bin
endef

# Add "/usr/include" in the include path to have access to "btrfs.h"
# These headers are not included in the Entware toolchain at $(STAGING_DIR)/opt/include
TARGET_CFLAGS += \
	-I/usr/include

# Added these flags to enable linker debugging
TARGET_CFLAGS += \
	-Xlinker --verbose

# Adding another path for libintl because the linker wrongly assumes that it's in $(STAGING_DIR)/opt/lib
TARGET_LDFLAGS += \
	-L$(STAGING_DIR)/opt/lib/libintl-full/lib

# The linker couldn't also find libiconv, so I added the hacky solution below.
# I tried using: -L$(STAGING_DIR)/opt/lib/libiconv-full/lib
# But it didn't work because gcc wouldn't use it during the linking process. 
# It gets used for linking other shared libraries, but not libiconv.
#
# So I tried using "rpath" instead and it seems to work, but I had issues to get a proper path.
# I noticed that if rpath starts with "/" (e.g. /home/...), then the generated gcc command will treat it as a relative path.
# If it starts with a non-slash character (e.g. example/opt/lib/...), it'll be treated as an absolute path, which is not what I want.
# I'm not sure why it's the case. Maybe it's a custom behavior of the compiled gcc from Entware?
#
# I previously tried using $ORIGIN in various ways but couldn't find a way to escape it properly.
# Either the generated gcc command fails because Make doesn't know how to escape it when generating intermediate bash commands, or the final command is incorrect.
# E.g. Those don't work:
# -Wl,-rpath,'$$$$ORIGIN'/libiconv-full/lib
# -Wl,-rpath,"'"'$$'ORIGIN"'"/libiconv-full/lib
# "'"'$'ORIGIN"'"

# Some dirname magic to get the relative path to the staging directory
PKG_REL_DIR := \
	$(shell dirname \
		$(patsubst \
			$(shell dirname \
				$(shell dirname $(PKG_BUILD_DIR)) \
			)/%,%,$(PKG_BUILD_DIR) \
		) \
	)
TARGET_LDFLAGS += \
	-Wl,-rpath,/../$(PKG_REL_DIR)/opt/lib/libiconv-full/lib

# DEBUGGING info
$(info PKG_BUILD_DIR: $(PKG_BUILD_DIR))
# E.g. PKG_BUILD_DIR: /home/me/Entware/build_dir/target-x86_64_glibc-2.33/duperemove-0.15.1
$(info TARGET_LDFLAGS = $(TARGET_LDFLAGS))
# E.g. TARGET_LDFLAGS = -Wl,--dynamic-linker=/opt/lib/ld-linux-x86-64.so.2 -Wl,-rpath=/opt/lib -L/home/me/Entware/staging_dir/toolchain-x86_64_gcc-12.3.0_glibc-2.33/usr/lib -L/home/me/Entware/staging_dir/toolchain-x86_64_gcc-12.3.0_glibc-2.33/lib -fuse-ld=bfd -L/

# I tried other alternatives like copying or creating simlinks to the shared libraries but it felt too hacky. Maybe it's the right way to do it?
# define Build/Configure
# $(call Build/Configure/Default,, \
# 	UNAME_S="Linux" \
# 	UNAME_R="$(LINUX_VERSION)" \
# 	UNAME_M="$(ARCH)" \
# )
# 	echo #####################################################	
# 	echo PKG_BUILD_DIR: $(PKG_BUILD_DIR)
# 	echo STAGING_DIR: $(STAGING_DIR)
# 	echo CC: $(CC)
# 	echo CFLAGS: $(CFLAGS)
# 	echo EXTRA_CFLAGS: $(EXTRA_CFLAGS)
# 	echo LDFLAGS: $(LDFLAGS)
# 	echo TARGET_CFLAGS: $(TARGET_CFLAGS)
# 	echo TARGET_LDFLAGS: $(TARGET_LDFLAGS)
# 	echo #####################################################
#
# # echo #####################################################
# # echo # Copy kernel headers to the staging directory
# # echo #####################################################
# # $(CP) /usr/include/linux $(STAGING_DIR)/opt/include
#
# 	# Create links to some shared libraries
# 	# I tried using '$ORIGIN' with LDFLAGS but couldn't find a way to escape it properly to please Makefile and the generated gcc command.
# 	# ln -sf $(STAGING_DIR)/opt/lib/libiconv-full/lib/* $(STAGING_DIR)/opt/lib
# endef

$(eval $(call BuildPackage,duperemove))