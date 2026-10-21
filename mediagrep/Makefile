# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2026 Tyler MacDonald

include $(TOPDIR)/rules.mk

PKG_NAME:=mediagrep
PKG_VERSION:=0.1.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/postmaxin/mediagrep/tar.gz/refs/tags/v$(PKG_VERSION)?
PKG_HASH:=3f39eed70293c83ac4f56ededae34f20d967a7e75083521383cc8eaa9187e505

PKG_MAINTAINER:=Tyler MacDonald <github@crackerjack.net>
PKG_LICENSE:=BSD-2-Clause
PKG_LICENSE_FILES:=LICENSE

CMAKE_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/mediagrep
	SECTION:=multimedia
	CATEGORY:=Multimedia
	DEPENDS:=+libmediainfo +libstdcpp
	TITLE:=grep for media file metadata
	URL:=https://github.com/postmaxin/mediagrep
endef

define Package/mediagrep/description
 mediagrep searches the metadata of audio, video and image files (tags,
 codecs, resolution, duration and so on) the way grep searches text.
 It loads MediaInfoLib when it starts.
endef

# MediaInfoLib is loaded with dlopen() at run time, so it is not linked here;
# MEDIAGREP_MEDIAINFO_LIBRARY is the path the binary will open.
CMAKE_OPTIONS += \
	-DMEDIAGREP_BUILD_TESTS=OFF \
	-DMEDIAGREP_MEDIAINFO_LIBRARY=/opt/lib/libmediainfo.so.0

define Package/mediagrep/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/mediagrep $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/share/man/man1
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/opt/share/man/man1/mediagrep.1 $(1)/opt/share/man/man1
	# The MediaInfoDLL headers are compiled into the binary, so MediaInfoLib's
	# BSD notice has to travel with it.
	$(INSTALL_DIR) $(1)/opt/share/doc/mediagrep
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/opt/share/doc/mediagrep/LICENSE $(1)/opt/share/doc/mediagrep
	$(INSTALL_DATA) $(PKG_INSTALL_DIR)/opt/share/doc/mediagrep/MediaInfoLib-License.html $(1)/opt/share/doc/mediagrep
endef

$(eval $(call BuildPackage,mediagrep))
