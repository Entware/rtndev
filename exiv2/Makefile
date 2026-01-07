# PDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=exiv2
PKG_VERSION:=0.28.7
PKG_REV:=afcb7a8ba84a7de36d2f1ee7689394e078697956
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/Exiv2/exiv2.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=ec372d6b7e663c004a093ac93aaccc563af8df1a3d535cdc7d2f29a9dfa3d379

CMAKE_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/exiv2/Default
	TITLE:=Image metadata library and tools
	URL:=http://www.exiv2.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/libexiv2
	$(call Package/exiv2/Default)
	SECTION:=libs
	CATEGORY:=Libraries
	DEPENDS:=+libexpat +libinireader +libstdcpp +zlib
	TITLE+= (library)
endef

define Package/exiv2
	$(call Package/exiv2/Default)
	SECTION:=multimedia
	CATEGORY:=Multimedia
	DEPENDS:=+libexiv2
endef

define Package/libexiv2/description
 library and a command-line utility to read, write, delete and modify Exif,
 IPTC, XMP and ICC image metadata.
endef

Package/exiv2/description = $(Package/libexiv2/description)

TARGET_CFLAGS += -Wno-deprecated -Wno-deprecated-declarations

CMAKE_OPTIONS += \
	-DEXIV2_ENABLE_BROTLI=OFF \
	-DEXIV2_ENABLE_VIDEO=ON \
	-DEXIV2_ENABLE_WEBREADY=ON \
	-DEXIV2_BUILD_SAMPLES=OFF

define Package/libexiv2/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/lib/libexiv2.so* $(1)/opt/lib
endef

define Package/exiv2/install
	$(INSTALL_DIR) $(1)/opt
	$(CP) $(PKG_INSTALL_DIR)/opt/bin $(1)/opt
endef

$(eval $(call BuildPackage,libexiv2))
$(eval $(call BuildPackage,exiv2))
