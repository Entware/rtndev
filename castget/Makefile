#
# Copyright (C) 2011-2016 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=castget
PKG_VERSION:=1.2.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=http://download.savannah.gnu.org/releases/castget
PKG_MD5SUM:=8410fb01d1ff66125c60250398d8c565

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

TARGET_LDFLAGS += \
	-Wl,-rpath-link=$(STAGING_DIR)/opt/lib/libiconv-full/lib

define Package/castget
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=File Transfer
	DEPENDS:=+libcurl +glib2 +libxml2 $(ICONV_DEPENDS) $(INTL_DEPENDS)
	TITLE:=a command-line podcast downloader
	URL:=http://www.nongnu.org/castget
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/castget/description
 castget is a simple, command-line based RSS enclosure downloader.
 It is primarily intended for automatic, unattended downloading of podcasts.
endef

CONFIGURE_ARGS += \
	--disable-id3lib

define Package/castget/conffiles
/opt/etc/castgetrc
endef

define Package/castget/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/castget $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/castgetrc.example $(1)/opt/etc/castgetrc
endef

$(eval $(call BuildPackage,castget))
