#
# Copyright (C) 2017-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=httrack
PKG_VERSION:=3.49.2
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://mirror.httrack.com
PKG_HASH:=3477a0e5568e241c63c9899accbfcdb6aadef2812fcce0173688567b4c7d4025

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/httrack
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=File Transfer
	DEPENDS:=+libopenssl +libpthread
	TITLE:=website copier
	URL:=http://www.httrack.com
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/httrack/description
 HTTrack is a free and easy-to-use offline browser utility. It allows you
 to download a WWW site from the Internet to a local directory, building
 recursively all directories, getting HTML, images, and other files from
 the server to your computer. HTTrack arranges the original site's relative
 link-structure.
endef

CONFIGURE_ARGS += \
	--with-zlib="$(STAGING_DIR)/opt"

define Package/httrack/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) \
		$(PKG_INSTALL_DIR)/opt/bin/{htsserver,httrack,proxytrack} \
		$(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/lib/httrack
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/httrack/*.so* \
		$(1)/opt/lib/httrack
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/*.so* \
		$(1)/opt/lib
	$(INSTALL_DIR) $(1)/opt/share/httrack/html
	$(CP) $(PKG_INSTALL_DIR)/opt/share/httrack/{lang,templates,lang.def,lang.indexes} \
		$(1)/opt/share/httrack
	$(CP) $(PKG_INSTALL_DIR)/opt/share/doc/httrack/* \
		$(1)/opt/share/httrack/html
endef

$(eval $(call BuildPackage,httrack))
