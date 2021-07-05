#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=exiv2
PKG_VERSION:=0.27.4
PKG_REV:=15098f4ef50cc721ad0018218acab2ff06e60beb
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/Exiv2/exiv2.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=4813904e12804c16db24167346218dab48435eecf65cc556cdb1292a93886f6c

CMAKE_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/devel/ninja/ninja-cmake.mk

define Package/exiv2/Default
	TITLE:=Image metadata library and tools
	URL:=http://www.exiv2.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/libexiv2
	$(call Package/exiv2/Default)
	SECTION:=libs
	CATEGORY:=Libraries
	DEPENDS:=+libexpat +libstdcpp +zlib
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
