#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=ziproxy
PKG_VERSION:=3.3.1
PKG_RELEASE:=2

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=@SF/ziproxy
PKG_HASH:=c39c6148840cdaa867d4dd3ad41d39be345494b2048b86ec899d0c075e56874d

include $(INCLUDE_DIR)/package.mk

define Package/ziproxy
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Web Servers/Proxies
	DEPENDS:=+giflib +libjpeg +libpng +libsasl2 +libpthread
	TITLE:=compressing HTTP proxy server
	URL:=http://ziproxy.sourceforge.net
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/ziproxy/description
 ziproxy is a forwarding, non-caching and compressing HTTP proxy server.
 Basically it squeezes images by converting them to lower quality JPEGs
 and compresses (gzip) HTML and other text-like data.
endef

define Package/ziproxy/conffiles
/opt/etc/xinetd.d/ziproxy
/opt/etc/ziproxy/ziproxy.conf
/opt/etc/ziproxy/bo_exception.list
/opt/etc/ziproxy/change_tos.list
/opt/etc/ziproxy/deny.list
/opt/etc/ziproxy/http.passwd
/opt/etc/ziproxy/noprocess.list
/opt/etc/ziproxy/replace.list
/opt/etc/ziproxy/replace_ct.list
/opt/etc/ziproxy/sasl/ziproxy.conf
endef

CONFIGURE_ARGS += \
	--without-jasper \
	--with-cfgfile=/opt/etc/ziproxy/ziproxy.conf

define Package/ziproxy/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) \
		$(PKG_BUILD_DIR)/src/ziproxy \
		$(PKG_BUILD_DIR)/src/tools/ziproxylogtool \
		$(PKG_BUILD_DIR)/src/tools/ziproxy_genhtml_stats.sh \
		$(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc/xinetd.d
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/etc/xinetd.d/ziproxy \
		$(1)/opt/etc/xinetd.d/ziproxy
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S25ziproxy $(1)/opt/etc/init.d/S25ziproxy
	$(INSTALL_DIR) $(1)/opt/etc/ziproxy/sasl
	$(INSTALL_CONF) \
		$(PKG_BUILD_DIR)/etc/ziproxy/ziproxy.conf \
		$(PKG_BUILD_DIR)/etc/ziproxy/http.passwd \
		$(PKG_BUILD_DIR)/etc/ziproxy/bo_exception.list \
		$(PKG_BUILD_DIR)/etc/ziproxy/change_tos.list \
		$(PKG_BUILD_DIR)/etc/ziproxy/deny.list \
		$(PKG_BUILD_DIR)/etc/ziproxy/noprocess.list \
		$(PKG_BUILD_DIR)/etc/ziproxy/replace.list \
		$(PKG_BUILD_DIR)/etc/ziproxy/replace_ct.list \
			$(1)/opt/etc/ziproxy
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/etc/ziproxy/sasl/ziproxy.conf \
		$(1)/opt/etc/ziproxy/sasl
	$(INSTALL_DIR) $(1)/opt/var/log/ziproxy $(1)/opt/var/run
endef

$(eval $(call BuildPackage,ziproxy))
